#include <thread>
#include <random>
#include <chrono>
#include <iostream>
#include <exception>
#include <functional>
#include <unistd.h>
#include <boost/thread.hpp>
#include <boost/thread/thread_pool.hpp>
#include <boost/asio.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/thread/executors/serial_executor.hpp>
#include <boost/thread/executors/inline_executor.hpp>
#include <boost/thread/executors/generic_executor_ref.hpp>


#include "future_fun.h"

int add(int a, int b) {
    std::cout << "sleep 2s" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return a + b;
}

void testPackagedTask() {
    boost::packaged_task<int> task(boost::bind<int>(add, 1, 2));
    boost::future<int> ret = task.get_future();
    boost::shared_future<int> shared_fut = ret.share();
    std::thread(std::move(task)).detach();
    //int value = ret.get();//ret已经变为非法
    int value = shared_fut.get();
    value = shared_fut.get();
    std::cout << value << "\n";
}

bool do_check_prime(int x)  {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

void testWaitFor() {
    //如果是std::launch::deferred 则延迟启动
    boost::future<bool> fut = boost::async(boost::launch::async, boost::bind<bool>(do_check_prime, 1));
    std::cout << "Checking...";
    // wait_until();
    while (fut.wait_for(boost::chrono::milliseconds(500)) == boost::future_status::timeout) {
        std::cout << '.';
    }
    fut.then([](decltype(fut) fut) {
        std::cout << "is prime " << fut.get() << "\n";
    });
}

boost::asio::io_service gIos;

void testThen() {
    boost::packaged_task<std::string> taskA(doA);
    boost::packaged_task<std::string> taskB(doB);
    boost::packaged_task<std::string> taskC(doC);
   // gIos.post(taskA);
    //gIos.post(taskB);
    //gIos.post(taskC);
    auto futureA = taskA.get_future().share();
    auto futureB = taskB.get_future().share();
    auto futureC = taskC.get_future().share();
    std::vector<decltype(futureA)> abc = { futureA, futureB, futureC };

    auto futureABC = boost::when_all(abc.begin(), abc.end()).share();
    auto futureX = futureABC.then([](decltype(futureABC) futureABC) {
        auto abc = futureABC.get();
        return doX(abc[0].get(), abc[1].get(), abc[2].get());
    }).share();


    auto futureAX = boost::when_all(futureA, futureX).share();
    auto futureZ = futureAX.then([](decltype(futureAX) fAX) {
        auto ax = fAX.get();
        return doZ(std::get<0>(ax).get(), std::get<1>(ax).get());
    }).share();

    auto futureXC = boost::when_all(futureX, futureC).share();
    auto futureY = futureXC.then([](decltype(futureXC) fXC) {
        auto xc = fXC.get();
        return doY(std::get<0>(xc).get(), std::get<1>(xc).get());
    }).share();

    auto futureZY = boost::when_any(futureZ, futureY).share();

    auto futureR = futureZY.then([](decltype(futureZY) fZY) {
        auto zy = fZY.get();
        if(std::get<0>(zy).is_ready()) {
            return  std::get<0>(zy).get();
        }
        return std::get<1>(zy).get();
    }).share();
    std::cout<<"all finish " << futureR.get();
}

class Result {
public:
    Result() {
        std::cout<<("construct")<< std::endl;
    }
    Result(const Result& other) {
        std::cout<<("copy construct")<< std::endl;
    }
    Result(Result&& other) {
        std::cout<<("move")<< std::endl;
    }
    Result& operator = (const Result& other) {
        std::cout<<("operator=")<< std::endl;
        return *this;
    }
};


typedef boost::executor_ref<boost::inline_executor> TsdbExecutor;
typedef boost::shared_ptr<TsdbExecutor> TsdbExecutorPtr;

boost::inline_executor gExecutor;
TsdbExecutorPtr gExecutorPtr(new TsdbExecutor(gExecutor));

boost::promise<int> test() {
    boost::promise<int> promise;
    promise.set_executor(gExecutorPtr);

    auto fut = promise.get_future();
    auto fut2 = fut.then([](decltype(fut) fut) {
        std::cout<< "then1" << __LINE__ << " tid:" << boost::this_thread::get_id() << std::endl;
        return int(2);
    });

    fut2.then([](decltype(fut) fut) {
        std::cout<< "then2" << __LINE__ << " tid:" << boost::this_thread::get_id() << std::endl;
    });

    return std::move(promise);
}

void testFuture() {
    auto fut = boost::make_ready_future((int)(1));
    fut.then([](decltype(fut) fut){
        std::cout<< "testFuture" << __LINE__ << " tid:" << boost::this_thread::get_id() << std::endl;
    });
}

int main() {
    std::cout<< "main" << __LINE__ << " tid:" << boost::this_thread::get_id() << std::endl;
    auto promise = test();
    promise.set_value(1);
    //testPackagedTask();
    //testWaitFor();
    //testThen();
    int cmd = 0;
    std::cin >> cmd;
    testFuture();
    std::cin >> cmd;
    return 0;
}
