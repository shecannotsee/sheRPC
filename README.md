这是一个简易的c++rpc demo

main函数模拟远程调用，您可以理解为：只要在进入main函数时，就类似于在C/S架构中，进入了服务器的处理范围

然后通过部分参数的传递，进行一个rpc的调用

类rpc_function是一个调用函数的模型，是一个在服务端等待调用的类（当然里面会包含很多方法）

类rpc_register是一个服务端的注册类，他的主要功能是解析从客户端传入的各种参数，这里包括1.需要调用的方法（在本次实验的细节中，方法分为了类和函数两部分，大意是为了兼容类）2.对应方法的参数（此实验的参数较为简单，均在string和int之间进行转换）

类rpc_register是一个静态注册类，需要在函数:regis()以及fool(std::string function_parameter)中手动编写注册规则以及调用规则，如果有反射的话我相信此处可以变得更加简洁 : )

