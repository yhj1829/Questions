//
//  FirstVC.h
//  面试汇总
//
//  Created by 阳光 on 16/12/5.
//  Copyright © 2016年 阳光. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FirstVC : UIViewController

@end

/*

 一. CALayer和UIView的区别联系
 1 UIView是UIKIt的只能在iOS使用, CALayer是QuartzCore的 iOS和mac os通用
 2 CALayer比UIView更加轻量级,但是可以实现同样的效果
 3 UIView的CALayer类似UIView的子View树形结构
 4 UIView比CALayer多了一个事件处理功能,也就是说UIView能处理用户触摸
 5 UIView有个重要的属性layer,可以返回它的主CALayer实例.CALayer *layer = myView.layer
 6 坐标系统: CALayer的坐标系统比UIView多了一个anchorPoint属性
 7 UIView是iOS系统中界面的基本元素,所有的界面元素都是继承自它.它本身完全是由CoreAnimation来实现的.它真正的绘图部分,是由一个CALayer类来管理的.UIView本身更像是一个CALayer的管理权,访问它的跟绘图和跟坐标有关的属性,如frame,bounds等,实际上内部都是在访问它所包含的CALayer的相关属性.
 layer可以设置圆角显示 cornerRadius 也可以设置阴影 shadowColor 但是如果layer��中某个layer设置了圆角 ��中所有layer的阴影效果将都不显示.因此要死设置有圆角还要阴影,可以做两个UIView重叠,一个layer显示圆角一个layer显示阴影
 8 渲染 当更新层 改变不能立即显示在屏幕上.当所有的层都准备好时,可以调用setNeedsDisplay方法来重绘显示.
 9 变换 要在一个层中添加一个3D或仿射变换,可以分别设置层的transform或者affineTransform属性
 10 变形Quartz Core的渲染能力 使二维图像可以被自由的操纵,就像是三维的.图像可以在一个三维坐标系中以任意的角度被旋转 缩放 和倾斜.CATransform3D的一套方法提供了一些魔术般的效果
 二. 简述同步和异步
 同步:串行的执行任务 异步:并行的执行任务.同步函数不具备开启线程的能力,而异步函数具备
 所谓同步,就是在发出一个调用时,在没有得到结果之前,该调用就不返回.但是一旦调用返回,就得到返回值了.也就是 由调用者主动等待这个调用结果
 而异步则是相反,调用在发出之后,这个调用就直接返回了,所以没有返回结果.换句话说就是当一个异步过程调用发出后，调用者不会立刻得到结果。而是在调用发出后，被调用者通过状态、通知来通知调用者，或通过回调函数处理这个调用.
 三. 多线程安全怎么控制?
 用互斥锁,队列组,栅栏函数,依赖
 四. 简要说明什么时候使用继承,什么时候使用类别
 在OC中,一个类继承另一个类,就是继承了父类所有的属性和方法,并且可以扩充自己的属性:而类别是在不改变原有类的基础上进行方法扩充;
 因此,根据开发需求,如果这个类需要扩充属性,或者需要重写系统的类的某些方法,用继承;如果只是对一个类扩充接口和模块,使用类别更加方便.
 五. 简述苹果的安全机制
 数字签名机制:在iOS中运行的App必须 拥有自己的数字签名,而数字签名来与开发者的数字证书;开发者需要加入"iOS开发者计划"才能获取证书 而且其开发的App还要经过严格的审查才能在AppStore上架,保证了App的安全;杜绝了第三方和未签名App的运行;
 沙盒保护机制:这种机制使得设备内的各个App之间无法直接进行交流,只能通过iOS来进行数据传递;虽然降低了系统的扩展性但是却保证了安全性;
 不要使用越狱,否则苹果的安全机制就功亏一篑;
 只从AppStore获取App;
 第一次连接计算机,不要随意点"信任";
 不要随意给某个App设置隐私读取权限;
 六 关键字const有什么含意?修饰类呢?static的作用,用于类呢?还有extern c的作用?
 当使用 const修饰基数数据类型变量时,该变量就变为常量,进入静态区
 当使用const修饰指针类型变量时:
 当使用const在指针类型两边,那么该指针变量指向的内存空间的内容就不能改变了,但指针的指向可以改变.
 如果const在变量的左边,那么该指针的指向不能改变了,而指向内存空间的内容可以改变
 当使用const修饰符时,const NSSting *str,相当于修饰该对象,表示对象是不可更改的.
 static修饰变量,表示这个内部全局变量,只能在本文件中访问.系统会将该变量放进静态区,它的生命周期被延长到了程序结束
 static修饰类, 表示这个内部的方法, 只能在本文件中访问.
 extern c表示声明了一外部变量, 多个外部变量如果同名,实际指向的是同一块存储空间.
 七. 类工厂方法是什么?
 类工厂方法的实现是为了向客户提供方便,它们将分配和初始化合在一个步骤中,返回被创建的对象,并进行自动释放处理.这些方法的形式是+(type)className..其中className不包括任何前缀. 工厂方法可能不仅仅为了方便使用,它们不但可以将分配和初始化合在一起,还可以为初始化过程提供对象的分配信息.类工厂方法的另一个目的是使类提供单间实例.
 八 UIView从出现到销毁的过程?
 -> loadView
 -> viewDidLoad
 -> viewWillAppear
 -> viewWillLayoutSubviews
 -> viewDidLayoutSubviews
 -> viewDidAppear
 -> viewWillDisappear
 -> viewDidDisappear
 九. 什么情况下回发生内存泄漏和内存溢出?
 内存溢出就是你要求分配的内存超出了系统能给你的,系统不能满足需求,于是就产生溢出.
 内存泄漏就是指你向系统申请分配内存进行使用,可以说使用完后没有惊喜释放,结果这块内存也无法分配给其他程序,称之为内存泄漏
 内存泄漏的累计危害非常大 最后会导致内存溢出 程序闪退;
 内存泄漏分为四大类;
 常发生内存泄漏:发生内存泄漏的代码会被多次执行到,每次被执行的时候都会导致一块内存泄漏.
 偶发生内存泄漏.发生内存泄漏的代码只有在某些特定的坏境或者操作过程下才会发生;
 一次性内存泄漏.发生内存泄漏的代码只会被执行一次,或者由于算法上的缺陷,导致总会有一块仅且一块内存发生泄漏;
 隐式内存泄漏 程序在运行的过程中不停的分配内存, 但是直到结束的时候才释放内存,对于运行周期很长的服务器,不及时释放会耗尽内存;
 十 说说响应者链条?
 响应者链条是一条由UIResponder的子类组成的链条,它们都能够响应时间,由事件的最佳相应者起,如果它是控制器的view的话,它的上一级响应者就是这个控制器,否则就是它的父控件;控制器的上一级响应者是它父控制器的view,最终一直到window.
 
 SDWebImage基本使用
 http://www.jianshu.com/p/e614270a53c7
 一. clear和clean的区别?
 clear 先把之前的缓存文件夹删除掉,然后在新建一个文件夹
 clean 先删除过期的文件,然后计算剩余缓存文件的大小(currrentSize)>maxSize,继续删除,按照它缓存文件创建的时间删除,直到(currrentSize)<=maxSize
 二. 内存缓存时间是多久?
 一周
 三.内存缓存机制?
 NSCache
 四. 最大并发数量
 6条
 五. SDWeblmage任务的执行?是怎么实现的?
 两种:先进先出和先进后出
 实现:依赖来实现的
 六. 默认的缓存路径
 沙盒下的default下
 七. 怎么处理图片的名称?
 对URL进行MD5加密
 八. 如何判读图片的第一个字节
 得到二进制的第一个字节
 九. 使用什么来下载图片的
 NSURLConnection这个类,用代理方法下载图片
 十. 默认的超时时间是多少?
 15秒
 -------------------加餐---------------------
 十一. 该框架内部对内存警告的处理方式?
 监听系统发出的警告通知,然后清空内存缓存
 十二. NSCache和字典的区别
 NSCache使用方法和可变字典类似80% 它线程安全 可设置缓存成本 ,通过代理方法能拿到被处理的对象
 可以自动清理缓存数据
 十三. 如何计算图片的成本?
 长宽缩放比例*缩放比例
 image.size.height * image.size.width * image.scale * image.scale
 十四 保证错误的URL不会被尝试重新下载
 因为内部设置了一个黑名单 (内部是NSMutableset)
 
 
 一. CGD的底层实现
 iOS和OS X的核心是XNU内核, GCD是基于XNU内核实现的
 GCD的API全部在libdispatch库中
 GCD的底层实现主要有Dispatch Queue 和Dispatch Source
 Dispatch Queue:管理block操作
 Dispatch Source:处理事件
 二. Notification是同步还是异步?kvo是同步还是异步
 包括代理,这些都是同步的;监听和回调都是在同一个线程中执行
 三. Objective C中的selector是什么?
 可以理解@selector()就是取类方法的编号,他的行为基本可以等同C语言中的函数指针,只不过C语言中,可以吧函数名之间赋给一个函数指针,而Objective-C的类不能之间应用函数指针,这样只能做一个@selector语法来取.
 它的结果是一个SEL类型,这个类型的本质是累方法的编号(函数地址).方法以selector为索引.selector的数据类型是SEL定义成char*,我们可以把它想象成int .每个方法的名字对应一个唯一的值.
 四. 那些操作是属于私有api的范畴?
 私有API是指存放在PrivateFrameworks框架中的API 是苹果明确不能使用的API 也可以说 一般在官方文档和头文件中看不到,但是实际存在于框架中的API 就是私有API,具体在提交应用的时候回自动检测.
 私有API的存在很大一部分是为了保护隐私和系统安全,进制开发者使用这些功能.但是由于Objective-C的动态特性 ,使得实际上不可能存在真正意义的阻止调用这些API.
 五. frame和bounds有什么不同
 frame的位置是相对父空间的左上角来说的 参照的是父类的坐标系,指的是空间在父控件内的位置和大小
 bounds的位置是相对控件自身的左上角来说的,参照的是自身坐标系,指的是自己本身的大小
 六. NSTimer和GCD的定时器有什么区别
 NSTimer 可以调用invalidate进行撤销,创建和撤销必须在同一线程
 NSTimer需要交定时器添加到当前的runloop中
 它的时间单位是秒
 GCD一旦执行就不能撤销
 GCD中的定时器不受runloop模式的影响
 时间单位是纳秒
 七. 应用程序的沙盒下,都有哪些文件夹?它们有什么特点?本地缓存一般存在哪个文件下?
 1 Documents
 
 将应用程序的数据文件保存在该目录下.不过这些数据类型仅限于不可以再生的数据,可再生的数据文件应该存在LIbrary/Cache下
 2 Library 它有两个子文件
 
 caches 主要是缓存文件,用户使用过程中缓存都可以保存在这些目录中.保存那些可再生的文件,比如网络数据请求.因此,应用程序通常还需要负责删除这些文件.
 Preferences 应用程序的偏好设置文件. 我们使用NSUserDefaults写的设置数据都会保存到该目录下的一个plist文件中 它会被iTunes同步
 3. tmp
 
 各种临时文件, 保存应用再次启动时不需要的文件.而且,当应用不在需要这些文件时应主动将其删除,因为该目录下的东西随时有可能被系统清除,目前已知的一种可能清理的原因是系统磁盘存储空间不足的时候
 八. 为什么要使用第三方框架
 使用第三方框架会大大的提高编码效率
 在完成功能时,三方框架一般性能优于我们编写的代码
 框架有许多值得我们学习的技术和思想
 但第三方框架的使用也有缺点,比如正是因为用第三份框架 所有在使用上回遇到一些意料之外的问题,比如框架作者不在更新框架
 九. 谈谈你对MVC的理解?
 MVC是一种设计模式，它强制的将应用程序的输入、处理、和输出分开。使用了MVC的应用程序被分为3个核心部件:试图(View)、模型(Model)、控制器(Controller)。它们各司其职，既分工明确又相互合作。
 首先视图接受用户输入请求，然后将请求传递给控制器，控制器再调用某个模型来处理用户的请求，在控制器的控制下，再将处理后的结果交给某个视图进行格式化输出给用户。MVC不仅实现了功能模块和显示模块的分离，同时它还提高了系统的可维护性、可扩展性和组件的可复用性.
 十. plist和pct文件的好处?
 plist文件以便用来储存数组或者字典,它是iOS中特有的存储方式.它可以将数据与代码隔离开,更便于数据的管理和展示.
 pch里面可以保存一些全局的宏和头文件.
 pch是预编译头文件,其中存放有工程中已有编译的部分代码;在以后建立工程时就不用重新编译这些代码.
 pch头文件的内容能被项目中的其他所有源文件共享访问
 存放一些全局的宏 (整个项目都用得上的宏)
 用来包含一些全部的头文件(整个项目都用得上的头文件)
 能自动打开或者关闭日志的输出功能
 pch弊端:每个文件都会导入,有效率问题.

 
 一. 简述iOS动画机制
 iOS分为显式动画,隐式动画
 显式动画: 对一些属性做指定的自定义动画，或者创建非线性动画，比如沿着任意一条曲线移动。
 隐式动画:主要是作用于非根层,也就是自己手动创建的layer,当对它的一些属性进行修改时,会自动产生一些动画效果
 二. 什么是UIKit?
 UIKit是iOS上的AppKit的变种，用于为iOS应用程序提供界面对象和控制器。
 与AppKit类似，UIKit框架有UIResponder，也采用事件(UIEvent类)机制。
 另外，iOS上的应用程序都是一个UIApplication实例。 所有的iOS应用程序都基于UIKit ,它提供了在屏幕上绘制的机制，捕获事件，和创建通用用户界面元素。
 UIKit也通过管理显示在屏幕上的组件来组织复杂的项目。
 使用UIKit可以：
 • 构建和管理你的用户界面
 • 捕获触摸和基于移动的事件
 • 呈现文字和web内容
 • 优化你的多任务程序
 • 创建定制的用户界面元素
 三. 三此握手,具体怎么交互?
 第一次握手：客户端发送syn(syn=j)包到服务器；并进入SYN_SEND状态，等待服务器确认
 第二次握手：服务器收到syn包，确认客户的SYN(ack=j+1),同时自己也发送一个SYN包（syn=k），即SYN+ACK包，此时服务器进入SYN_RECV状态
 第三次握手：客户端收到服务器的SYN+ACK包，向服务器发送确认包ACK(ack=k+1)，此包发送完毕，客户端和服务器进入ESTABLISHED状态，完成三次握手。
 注意：三次握手中发送的包不包含数据，三次握手完毕，客户端和服务器才正式开始传送数据。TCP连接一旦建立，在通信双方的任何一方主动关闭连接之前，TCP连接都将被一直保持下去
 四. 什么是安全释放?
 对象呗释放的时候,指向nil
 五. 在iphone上有两件事情要做,请问是在一个线程里按顺序做效率高还是两个线程里做效率高？
 如果两件事有依赖关系,事件二必须等到事件一执行完毕才执行,那么放在一个线程就可以了,如果两者并没有什么关联,放到两个线程并发执行效率较高
 六. 4、NSArray和NSSet有何区别？
 NSSet: 里面存放的元素是无序的,不重复的,可以通过anyObject来访问单个元素.在搜索一个一个元素时NSSet比NSArray效率高，主要是它用到了数据结构中的哈希算法,而NSArray则是需要遍历全部的数组元素,效率会低一些.
 NSArray : 里面存放的元素是有序的,可以有重复的对象,可以通过下标来访问里面的数组元素
 七. __weak什么时候用?
 当两个对象互相引用的时候,一端用strong,另一端必须用weak .例如: A拥有B, B也拥有A, 那么必须一方使用weak
 一般UI控件都可以使用weak,因为自身已经对它进行一次强引用,没有必要再强引用一次.
 八. 列举几个常用集合类和存放二进制数据类？
 NSArray,NSDictionary,NSSet,以及他们的可变类
 存放二进制的有NSData类
 九. 多线程，写出常用的几个类
 Pthread
 NSThread
 GCD
 NSOperationQueue
 十. 一般在哪个函数中创建某个View的子view？
 viewDidLoad方法

 
 一. 用一个属性引用UI控件的时候为什么可以用weak?
 controller 是被系统用强指针引用者 只要它存在 那么里面的子控件也就存在 controller强引用着它的view controller又强引用着它的数组对象subviews 数组对象又强引用着它所包含的数组内容 那么创建出来的一个UI控件将其加入subviews的时候 那么就会被一个强指针所引着它
 内存的合理使用 当控件我们需要的时候就已经有一个强引用在引用着它 我们就不必再弄一个强指针来强引用它 当我们不需要的时候 weak直接释放掉 用strong的话就还会保留它 这就还占着内存了.
 二. UITableView 性能优化的原理
 iOS设备内存有限 如果使用UITableView显示非常多的数据 就需要非常多的UI TableViewcell
 那么设备的内存就会耗尽 解决该问题就需重用 UITableView 对象
 当滚动出列表的时候 部分UITableViewCell 会移出窗口 UITableView会将窗口外的UITableVIewcell 放入一个对象缓存池中
 当UITableView 要求dataSource 返回UITableView时 dataSource 会先查看缓存池中是否有未使用的UITableViewCell 有就用新的数据配置这个UITableViewCell 重新使用到窗口 就避免了重新创建对象
 三. 什么是抽象类 有什么作用?能实例化吗?
 abstract修饰，它只能用来作父类，本身并没有生成实例的能力
 它将一类最公有的属性和方法抽取出来抽象类是将类共有的方法抽取出来，声明为抽象方法, 抽象方法只有声明没有具体的实现, 拥有抽象方法的类就是抽象类; 这样新增一种类型时候只需要继承抽象类，实现抽象方法就可以了，降低了实现新类的难度。
 抽象方法修饰符 abstract 抽象类不能被实现
 如果一个类中没有包含足够的信息来描绘一个具体的对象，这样的类就是抽象类
 为什么要有抽象类？
 用于类型隐藏在面向对象领域，抽象类主要用来进行类型隐藏。我们可以构造出一个固定的一组行为的抽象描述，但是这组行为却能够有任意个可能的具体实现方式。这个抽象描述就是抽象类。
 用于拓展对象的行为功能
 这一组任意个可能的具体实现则表现为所有可能的派生类（子类），模块可以操作一个抽象体。由于模块依赖于一个固定的抽象体，因此它可以是不允许修改的；同时，通过从这个抽象体派生，也可扩展此模块的行为功能。
 四. objc中向一个nil对象发送消息会发生什么?
 没事
 五. runloop和线程有什么联系?
 Runloop和线程的关系：一个Runloop对应着一条唯一的线程
 问题：如何让子线程不死
 回答：给这条子线程开启一个Runloop
 Runloop的创建：主线程Runloop已经创建好了，子线程的runloop需要手动创建
 Runloop的生命周期：在第一次获取时创建，在线程结束时销
 六. 什么是懒汉模式,一般用在哪些地方?
 懒加载,指得是需要用到的时候才加载,其好处是节省内存空间,不必一开始就创建所有的变量,用到了就创建一块内存,同时也加快了程序运行速度.一般用于我们只需要创建一次的变量就可以的地方,例如字典转模型的数组,以及控制器的view等,都是懒加载的
 七. 常用的延时执行的几种方式?
 perform selector
 NSTimer
 GCD:dispatch_after
 八写出你想到的设计模式,并简要描述?
 单例模式:不管怎么创建,拿到的对象都是同一个
 MVC:MVC把软件系统分为三个部分：Model，View，Controller。MVC有低耦合性、高重用性、可维护性等优点
 代理模式:代理模式就是实现消息传递的一种机制,委托方有一些任务自己不想完成,但是还需要要实现,则将该任务存放到协议中,由代理完成.但是代理并不会主动的执行任务,需要委托方通知代理,然后代理完成委托方交给的任务.
 观察者模式:经典观察者模式定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象。这个主题对象在状态上发生变化时，会通知所有观察者对象，使它们能够自动更新自己或者做出相应的一些动作。比如KVO,通知中心
 九. 是否使用过CoreText或者CoreImage等？如果使用过，请谈谈你使用CoreText或者CoreImage的体验？
 用过
 CoreText是用于处理文字和字体的底层技术。Quartz能够直接处理字体（font）和字形（glyphs），将文字渲染到界面上，它是基础库中唯一能够处理字形的模块。因此，CoreText为了排版，需要将显示的文本内容、位置、字体、字形直接传递给Quartz。相比其它UI组件，由于CoreText直接和Quartz来交互，所以它具有高速的排版效果。
 coreImage是IOS5中新加入的一个Objective-c的框架，提供了强大高效的图像处理功能，用来对基于像素的图像进行操作与分析. iOS提供了很多强大的滤镜(Filter)，其中IOS5中有48种，而到了最新的IOS6 Filter已经增加到了93种之多，并且这一数字会继续增加。这些Filter提供了各种各样的效果，并且还可以通过滤镜链将各种效果的Filter叠加起来，形成强大的自定义效果，如果你对该效果很满意，还可以子类化滤镜
 十. POST、GET的区别？
 POST:将参数放在请求体中,参数的大小原则上没有限制一般传输的数据包含隐私相关的用POST
 GET:将参数附加在URL后面,因为URL长度的限制,所以参数的大小是有限制的,通常不能超过1KB
 GET 在请求URL后面以?的形式跟上发给服务器的参数,多个参数之间用&隔开

 
 一. 有网络链接的应用中,在取得数据后将json字符串通过框架转为NSDictionary或NSArray,很多人直接使用这些数据来更新UI,说说这样做的缺点,并给出解决办法?
 在书写的时候有可能写错Key值或者数组角标
 扩展性不好,且不符合MVC思想
 会造成数据的重复下载,消耗用户的流量,降低用户体验.
 如果没有网络或者网络堵塞,那么UI界面接受不到任何数据,显示不了任何内容,用户体验糟糕;
 解决的办法就是通过框架转换为字典或者数组后,在转化模型,并进行二级缓存,需要显示的时候从沙盒中取;
 利用框架字典转模型重写命名
 二. id声明的对象有什么特征?
 id声明的对象具有运行时的特性,即可用指向任意类型的Objcetive-c的对象,与C中void*的万能指针相似.
 在编译阶段不知道它的真实类型,运行时才能知道它的真实类型,所以id类型也不能使用点语法是编译时特性,而且id是运行时特性
 三. 你碰到那些导致程序闪退的原因?如何定位闪退的位置?
 函数无线递归
 运行时,找不到方法(没实现)
 访问了某个已经被释放的对象
 程序占用内存或CPU过高
 子线程阻塞主UI线程过久
 从Bundle加载了不存在或者不支持的对象
 等等....
 1 在设置断点的地方,选Add Exception Breakpoint.之后crash就会停在出错的位置.
 2 如果是在测试阶段报错的话,可以在(设置 - 通用 -关于本机 -诊断与用量)里面看到崩溃的堆栈信息.
 3如果用RAC的话,访问到已经释放了的内存,和内存警告这2种粗出错的几率高一些
 四. 如何实现圆角矩形?有哪些方法可以实现扇形View?
 直接修改view的样式，系统提供好的了
 view.layer.cornerRadius = 6;
 view.layer.masksToBounds = YES;
 用layer做就可以了,十分简单.需要库QuartzCore.framework；
 画矩形直接利用UIBezierPath给我们封装好的路径方法
 (x,y)点决定了矩形左上角的点在哪个位置
 (width,height)是矩形的宽度高度
 bezierPathWithOvalInRect:CGRectMake(x, y, width, height)
 [UIBezierPath bezierPathWithOvalInRect:CGRectMake(50, 50, 100, 100)];
 圆角矩形的画法多了一个参数,cornerRadius
 cornerRadius它是矩形的圆角半径.
 通过圆角矩形可以画一个圆.当矩形是正方形的时候,把圆角半径设为宽度的一半,就是一个圆.
 UIBezierPath*path = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(50,50,100,100) cornerRadius:50];
 扇形:
 画扇形的方法为:先画一个圆孤再添加一个一根线到圆心,然后关闭路径.
 关闭路径就会自动从路径的终点到路径的起点封闭起下
 用填充的话,它会默认做一个封闭路径,从路径的终点到起点.
 [path fill];
 五. Cocoa Touch提供了哪几种CoreAnimation过渡类型?
 Cocoa Touch提供了4中 Core Animation 分别是交叉淡化 推挤 显示和覆盖.
 六. 能否向编译后得到的类中增加实例变量?能否向运行时创建的类中添加实例变量,为什么?
 不能向编译后得到的类中增加实例变量
 因为编译后的类以及注册在runtime中,类结构同中objc_ivar_list实例变量的链表和instance_size实例变量的内存大小已经确定
 同时runtime会调用class_setlvarLayout或class_setWeakIvarLayout来处理 strong weak 引用。所以不能向存在的类中添加实例变量
 能向运行时创建的的类添加实例变量运行时创建的类是可以添加实例变量，调用 class_addIvar 函数。但是得在调用 objc_allocateClassPair 之后，objc_registerClassPair 之前，原因同上。
 七. 请写出你调试解决crash问题的思路及步骤?1）把问题拆分成多个小问题，一步步检验，直到找到问题的根源点
 2）程序运行后，查看log信息，找到错误的地方
 3）在错误的地方设置断点进行调试，可以加条件断点
 4）查看断点运行的信息，进行修改
 5).如果是在测试阶段报错的话，可以在（设置-通用-关于本机-诊断与用量）里面看到崩溃的堆栈信息。
 6).如果用rac的话，访问到已经释放了的内存，和内存警告这2种出错几率要高些。
 八. NSDictionary类使用了哪些数据结构和算法?
 NSDictionary 使用Hash表实现Key／Object存储;
 Hash表是一种访问速度很快的数据结构，前提是Hash函数设计合理，能够使数据在各个子节点均匀分布，这一点使用NSString对象可以保证，这是文档中的说明：
 Classes such as NSString that are part of Foundation have a good hash function.
 九. iOS和iPhone做了哪些设计来降低功耗,延长续航时间?作为应用的开发者,又如何避免费电?
 iOS的省电机制主要有以下几种：
 强化的后台机制
 墓碑式：伪多任务，应用推至后台后，虽然没有被关闭，但是所有活动都被冻结，只能通过苹果服务器转发的推送来与用户交互
 智能调度后台：在一些指定类别的APP，比如社交、新闻类的应 用中，iOS系统会根据应用启动频率、时间和当前网络和电量的状况来智能分配每个应用的后台数据获取频率和启动时长，开发者自己不能设置数据具体什么时候更新
 真后台：苹果也提供一些有诸多限制的接口来保证真后台，只供特定应用行为调用，比如后台音频，定位，上传下载等。
 作为开发者如何省电
 ◦ 首先当然优化代码，积极合理地使用runloop，多线程等技术。
 ◦ 其次是尽量少地调用一些费电的接口，比如频繁的定位，频繁的后台更新数据，如无必要，尽量不用。
 十. ARC内存管理原则是什么
 永远不写retain,release和autorelease三个关键字就好~这是ARC的基本原则。
 
 
 一. Notification和KVO有什么不同？KVO在ObjC中是怎么实现的？
 KVO:只能监听属性值的变化,而且有一定的弊端;
 在别处修改了属性,也会调用KVO的方法,可能会造成数据错乱
 当给一个对象添加监听后,会生成这个类的子类.NSKvoNotifying,并重写被监听属性的set方法;在开发中如果创建了同名的类,会报错
 使用Objective-C 强大的runtime功能实现了这个功能。属性类class中并没有实现KVO通知的相关方案，而是在调用addObserver之后定义属性类的子类subclass，subclass里边实现了属性的setter方法，setter方法中实现发动通知的功能。然后subclass中实现class函数，还让返回属性类的class，再让属性类对象的isa指向subclass，这样就伪装成表面上看还是属性类自己实现的通知功能。通过原理我们可以看出 必须使用属性方法或者setValue:forKey方法赋值才会发送通知，直接赋值是不会收到通知的
 二. UIViewController类中didReceiveMemoryWarning默认的操作是什么？
 当程序接到内存警告时View Controller将会收到这个消息：didReceiveMemoryWarning
 从iOS3.0开始，不需要重载这个函数，把释放内存的代码放到viewDidUnload中去。
 这个函数的默认实现是:检查controller是否可以安全地释放它的view(这里view指的是controller的view属性)，比如view本身没有superview并且可以被很容易地重建（从nib或者loadView函数）。
 如果view可以被释放，那么这个函数释放view并调用viewDidUnload。
 你可以重载这个函数来释放controller中使用的其他内存。但要记得调用这个函数的super实现来允许父类（一般是UIVIewController）释放view。
 如果你的ViewController保存着view的子view的引用，那么，在早期的iOS版本中，你应该在这个函数中来释放这些引用。而在iOS3.0或更高版本中，你应该在viewDidUnload中释放这些引用。
 三. 存放数字用什么类型？存放CGRect用什么类？
 NSNumber存放数字,NSValue可以存放CGrect
 四. 什么是沙箱模型
 沙箱模型就是指iOS的每一个程序对应到APP自己的一个目录，这个目录只有这个应用有读写权限，其他任何APP都没有这个目录的读写权限。这个APP对应的这个目录，就好比是这个app的沙箱。
 沙箱的作用就是保证APP数据的安全性，防止恶意软件、病毒等窃取信息。
 五. 简述HTTP通信中的阻塞与非阻塞方式
 阻塞模式和非阻塞模式的主要区别在于无请求来到时，阻塞模式会一直停在接收函数即accep函数，直到有请求到来才会继续向下进行处理。
 而非阻塞模式下，运行接收函数，如果有请求，则会接收请求，如果无请求，会返回一个负值，并继续向下运行。一般来说，使用阻塞模式
 的程序比较多，因为阻塞模式是由内核保障等待请求的，当他阻塞时不占用系统资源，而非阻塞模式需要我们人工轮询，占用资源较多。
 另外，阻塞模式可以使用select函数设置超时时间，具体可以参考相关书籍。
 六. HTTP报文中Content-type有和作用
 在Http协议消息头中，使用Content-Type来表示具体请求中的媒体类型信息
 七. 如何用css实现文字阴影
 CSS中有两种阴影效果,一种是DropShadow(投影),另一种是Shadow(阴影).
 (1)DropShadow
 语法
 {FILTER:DropShadow(Color=color,OffX=offX,OffY=offY,Positive=positive)}
 Color 代表投影的颜色，格式为“#RRGGBB”
 OffX 和 OffY 代表x和y方向的投影偏移量。必须用整数值，正数代表x轴的右方向和y轴的下方向。负值相反。
 Positive 参数是一个布尔值。值为true(非0),那么就为任何的非透明像素建立可见的投影。如果值为false(0)，那么就为
 透明的像素部分建立可见的投影。
 (2)Shadow
 语法
 {FILTER:Shadow(Color=color,Direction=direction)}
 Color 代表阴影的颜色，格式为“#RRGGBB”
 Direction是设置投影的方向，按照顺时针方向进行，0度代表垂直向上，然后每45度为一个单位。默认值是向左的270度。共8个方向。
 八. NSTimer是否是多线程的?使用时是否要加同步锁?
 不是,只能加到RunLoop中特定模式下才能工作;不需要,因为它只在单一线程工作
 九. main函数执行之前和执行之后,有可能分别会执行什么代码
 全局对象的构造函数会在main 函数之前执行，
 全局对象的析构函数会在main函数之后执行；
 用atexit注册的函数也会在main之后执行。
 一些全局变量、对象和静态变量、对象的空间分配和赋初值就是在执行main函数之前,而main函数执行完后,还要去执行一些诸如释放空间、释放资源使用权等操作
 进程启动后，要执行一些初始化代码（如设置环境变量等），然后跳转到main执行。全局对象的构造也在main之前。
 十. 父类未实现的delegate是否可以由子类实现
 可以,父类遵守的协议,子类也会继承这个协议
 
 
 一. 请简述iOS中Push原理
 第一阶段:应用程序把要发送的消息 目的iPhone的标识打包,发给APNS.
 第二阶段:APNS在自身的已注册Push服务的iPhone列表中,查找 有相应标识的iPhone,并把消息发送到iPhone.
 第三阶段:iPhone把发来的消息传递给相应的应用程序,并且按照设定弹出Push通知
 二. iOS7和iOS7以下常见的兼容性问题和解决方法?
 baseline
 原因:autolayout自动加了baseline的constraints，而baseline只有iOS8以后才有，兼容iOS7就崩溃了
 解决:直接移除baseline相关的constraint即可。
 [[UINavigationBar appearance] setTranslucent:NO]
 原因iOS8.0之后[UINavigationBar appearance]才可以setTranslucent，兼容iOS7需要添加判断
 解决:兼容iOS7需要添加判断
 if(IOS8_OR_LATER && [UINavigationBar   conformsToProtocol:@protocol(UIAppearanceContainer)]) {
 [[UINavigationBar appearance] setTranslucent:NO];
 }
 storyboard segue show
 原因:在iOS7下如果没有设置navigationController为initController，show会自动将push转换成modal。简而言之就是在sb里每个show的segue
 解决:保证它的初始位置有个navigationController。
 constrain to margin
 原因:这是设置了constrain to margins的关系，这玩意也是iOS8后才有的
 scrollerView
 原因:找不到setAutomaticallyAdjustsScrollViewInsets:方法
 解决:重写方法setAutomaticallyAdjustsScrollViewInsets:
 三. 怎么用 copy 关键字
 一般使用retain或者strong修饰属性时,是使用引用对象的指针指向同一对象,即为同一块内存地址.只要其中有一个指针变量被修饰时所有其他引用该对象的变量都会被改变
 而使用copy关键字修饰在赋值时是释放旧对象,拷贝新对象内容.重新分配了内存地址.以后该指针变量被修改时就不会影响旧对象的内容了.
 copy只有实现了NSCopying协议的对象类型才有效,常用于NSString和Block
 四. 这个写法会出什么问题
 @@property (copy) NSMutableArray *array;
 当一个NSMutableArray对象使用initWithArray: 初始化方法创建时，并将该对象赋值给了array属性。那么之后array执行可变数组的方法,如： removeObjectAtIndex: 时会出现unrecognized selector sent to instance的崩溃。原因在于array属性在被赋值(setter)的时候默认执行了copy方法后变为了不可变NSArray对象。
 五. 如何让自己的类用 copy 修饰符？如何重写带 copy 关键字的 setter？
 该类必须要实现NSCopying协议。实现 - (id)copyWithZone:(NSZone *)zone; 方法。
 重写copy关键字的setter时，需要调用一下传入对象的copy方法。然后赋值给该setter的方法对应的成员变量。
 六. 怎样防止指针的越界使用问题?
 防止数组越界，必须让指针指向一个有效的内存地址,
 防止向一块内存中拷贝过多的内容
 防止使用空指针
 防止改变const修改的指针
 防止改变指向静态存储区的内容
 防止两次释放一个指针
 防止使用野指针
 七. http请求方式有哪些？
 GET
 HEAD
 PUT
 DELETE
 POST
 OPTIONS
 八. 属性readwrite，readonly，assign，retain，copy，nonatomic 各是什么作用，在那种情况下用?
 readwrite 是可读可写特性;需要生成getter方法和setter方法时
 readonly 是只读特性 只会生成getter方法 不会生成setter方法 ;不希望属性在类外改变
 assign 是赋值特性，setter方法将传入参数赋值给实例变量;仅设置变量时;
 retain 表示持有特性，setter方法将传入参数先保留，再赋值，传入参数的retaincount会+1;
 copy 表示赋值特性，setter方法将传入对象复制一份;需要完全一份新的变量时。
 nonatomic 非原子操作，决定编译器生成的setter getter是否是原子操作，atomic表示多线程安全，
 一般使用nonatomic
 九. http 的post与get区别与联系，实践中如何选择它们？
 get是从服务器上获取数据,post是向服务器传送数据.
 get方式提交数据最多只能有1kB,而POST一般没有限制.
 安全性问题,使用get参数会在URL中,而pot不会,所以用户输入的数据包含敏感数据用post.
 十. 检查内存管理问题的方式有哪些?
 Xcode自带检测工具.
 
 
 
 
 
 
 一. @property的本质是什么?ivar,getter.setter是如何生成并添加到这个类中的.
 property在编译时编译器会自动的为我们生成一个私有成员变量和setter与getter方法的声明和实现.反编译property大致生成五个东西
 OBJC IVAR $类名$属性名称 该属性的偏移量
 setter与getter方法对应的实现函数
 ivar_list就是成员变量列表
 method_list方法列表
 prop_list 属性列表
 也就是说我们每次增加一个属性,系统都会在ivar_list中添加一个成员变量的描述,在method_list中增加setter与getter方法的描述,在属性列表中增加一个属性的描述,然后计算该属性在对象中的偏移量,然后产生setter与getter方法对应的实现,在setter方法方法中从偏移量的位置开始赋值,在getter方法中从偏移量开始取值,为了能够读取正确字节数,系统对象偏移量的指针类型进行了类型强转。
 二. @synthesize和@dynamic分别有什么作用
 @property有两个对应的词，一个是@synthesize，一个是@dynamic。如果@synthesize和@dynamic都没写，那么默认的就是@syntheszie var = var，var为property变量。可以手动修改属性var对应的实例变量。例如：@syntheszie var = var1
 @synthesize的语义是如果你没有手动实现setter方法和getter方法，那么编译器会自动为你加上这两个方法, 在Xcode4.4之后的版本可以省略不写.
 
 @dynamic告诉编译器不要自动生成成员变量的getter和setter方法，而是开发者自己手工生成或者运行时生成.
 三. 用@property声明的NSString（或NSArray，NSDictionary）经常使用copy关键字，为什么？如果改用strong关键字，可能造成什么问题？
 使用copy的目的是为了让本对象的属性不受外界影响,使用copy无论给我传入一股可变对象还是不可对象,我本身就是一股不可变副本.
 如果使用strong.这个属性有可能指向一个可变对象,如果这个可变对象呗外部意外的修改了,由于可变对象呗改变之后起始地址不会发生变化.而strong修饰的属性依然会指向这块内存地址,下次读取的时候就会是被改变以后的对象了, 也就是说strong可能会被外部意外修改.
 四. 属性readwrite，readonly，assign，retain，copy，nonatomic 各是什么作用，在那种情况下用?
 readwrite 是可读可写特性;需要生成getter方法和setter方法时
 readonly 是只读特性 只会生成getter方法 不会生成setter方法 ;不希望属性在类外改变
 assign 是赋值特性，setter方法将传入参数赋值给实例变量;仅设置变量时;
 retain 表示持有特性，setter方法将传入参数先保留，再赋值，传入参数的retaincount会+1;
 copy 表示赋值特性，setter方法将传入对象复制一份;需要完全一份新的变量时。
 nonatomic 非原子操作，决定编译器生成的setter getter是否是原子操作，atomic表示多线程安全，
 一般使用nonatomic
 五. 原子(atomic)跟非原子(non-atomic)属性有什么区别?
 atomic提供多线程安全。是防止在写未完成的时候被另外一个线程读取，造成数据错误
 non-atomic:在自己管理内存的环境中，解析的访问器保留并自动释放返回的值，如果指定了 nonatomic ，
 那么访问器只是简单地返回这个值。
 六. 在iOS应用中如何保存数据
 通过web服务, 保存在服务器上
 通过NSCoder固化机制,讲对象保存在文件中
 通过Sqlite或CoreData保存在文件数据库中
 七. 关键字volatile有什么含义？并给出三个不同例子
 　一个定义为volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。精确地说就是，
 　　优化器在用到这个变量时必须每次都小心地重新读取这个变量的值，而不是使用保存在寄存器里的备份。
 　　下面是volatile变量的几个例子：
 　　1） 并行设备的硬件寄存器（如：状态寄存器）
 　　2） 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables)
 　　3）多线程应用中被几个任务共享的变量
 八. 一个指针可以是volatile么?解释为什么
 可以是
 尽管这种情况并不常见,但它还是可以,例如
 当一个中断服务子程序企图去修改一个指向一个buffer指针的时候.
 九. 谈谈obj - c的优缺点
 优点
 分类特有语法.可以在不改变原有类的基础上,增加新的方法.
 动态识别
 弹性讯息传递
 objective -C 和 C++可混合编程
 缺点
 不支持命名空间机制:须在其类别名称加上前缀,时常引致冲突.
 不支持运算符重载(所谓重载，就是重新赋予新的含义。例如，大 家都 已习惯于用加法运算符”+”对整数、单精度数和双精度数进行加法运算，如5+8， 5.8 +3.67等，其实计算机对整数、单精度数和双精度数的加法操作过程是很不相同的， 但由于C++已经对运算符”+”进行了重载，所以就能适用于int, float, doUble类型的运算。)
 不支持多重继承
 弱语言,很多错误发生在运行时,不方便调试.
 十. 堆和栈的区别
 栈:向低地址扩展的数据结构，是一块连续的内存的区域。栈顶的地址和栈的最大容量是 系统预先规定好的，从栈获得的空间较小。
 堆:向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。
 碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出
 分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由 alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。
 分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的。
 
 
 一. 运行时你是怎么理解的,怎么用
 ObjC Runtime 其实是一个 Runtime 库，基本上用 C 和汇编写的，这个库使得 C 语言有了面向对象的能力。这个库做的事情就是加载类的信息，进行方法的分发和转发之类的。OC是一种面向runtime(运行时)的语言，也就是说，它会尽可能地把代码执行的决策从编译和链接的时候推迟到运行时。这给程序员写代码带来很大的灵活性，比如说你可以把消息转发给你想要的对象，或者随意交换一个方法的实现之类的。这就要求runtime能检测一个对象是否能对一个方法进行响应，然后再把这个方法分发到对应的对象去。我们拿 C 来跟 ObjC 对比一下。在 C 语言里面，一切从 main 函数开始，程序员写代码的时候是自上而下地，一个 C 的结构体或者说类吧，是不能把方法调用转发给其他对象的。这个问题其实涉及到两个概念，运行时和多态。 简单来说，运行时机制使我们直到运行时才去决定一个对象的类别，以及调用该类别对象指定方法。 多态：不同对象以自己的方式响应相同的消息的能力叫做多态。意思就是假设生物类（life）都用有一个相同的方法-eat; 那人类属于生物，猪也属于生物，都继承了life后，实现各自的eat，但是调用是我们只需调用各自的eat方法。 也就是不同的对象以自己的方式响应了相同的消息 响应了eat这个选择器。因此也可以说，运行时机制是多态的基础。比如KVO中我们就用了。
 二. 你单例怎么理解怎么用的?
 单例设计模式,一个类只有一个实例,而且该实例易于外界访问,方便对实例个数的控制并节约系统资源。类只能有一个实例，而且必须从一个为人熟知的访问点对其进行访问，比如工厂方法。在程序中，我需要一系列的对象，他们每一个内部都包含有一组变量和功能，是静态的，而且整个程序都只需要拥有一个该类的对象。例如：
 1.登陆界面(点击多个地方都弹出相同的控制器)；
 2.管理数据库；
 3.音效控制；
 4.文件处理:
 5.封装网络工具类等等...
 三. 说说oc这门语言吧，和c \ c++比，你觉得哪个效率高，高到哪里了?
 object_c比C++稍慢，是因为object_c的一些语言特性，比如反射，影响了执行效率。区别主要有以下一些方面。
 单一继承：Objective-C不支持多重继承，（同Java和Smalltalk），而C++语言支持多重继承。
 动态：Objective-C是动态定型（dynamicaly typed)所以它的类库比C++要容易操作。Objective-C 在运行时可以允许根据字符串名字来访问方法和类，还可以动态连接和添加类。C++ 跟从面向对象编程里的Simula67(一种早期OO语言）学派，而Objecive-C属于Smalltalk学派。
 在C++里，对象的静态类型决定你是否可以发送消息给它，而对Objecive-C来说，由动态类型来决定。Simula 67学派更安全，因为大部分错误可以在编译时查出。而Smalltalk学派更灵活，比如一些Smalltalk看来无误的程序拿到Simualr 67那里就无法通过。从很多方面来看，C++和Objective-C的差别，与其说时技术上的，不如说是思维方式上的...
 四. 代理,通知,KVO 各有什么优缺点
 代理优势:
 1.语法严格,将要监听的事件必须是delegate协议中有清晰的定义
 2.如果delegate中的一个方法没有实现那么就会出现编译警告/错误
 3.在一个应用中的控制流程是可跟踪的并且是可识别的；
 4.在一个控制器中可以定义定义多个不同的协议，每个协议有不同的delegate
 5.没有第三方对象要求保持/监视通信过程。
 代理缺点
 1.需要编写很多代码.
 定义delegate属性时,需要注意strong\weak的问题.
 3.一般用于父子关系,层级结构不能太复杂.
 通知优点
 1.不需要编写太多代码,实现比较简单.
 2.对于一个发出的通知，多个对象能够做出反应，即1对多的方式实现简单.
 3.controller能够传递context对象（dictionary），context对象携带了关于发送通知的自定义的信息
 4.层级结构比较深的时候用.
 通知缺点
 1.在编译期不会检查通知是否能够被观察者正确的处理；
 2.在释放注册的对象时，需要在通知中心取消注册；
 3.在调试的时候应用的工作以及控制过程难跟踪；
 4.观察者需要提前知道通知名称.
 5.通知发出后，controller不能从观察者获得任何的反馈信息。
 KVO优点
 1.能够提供一种简单的方法实现两个对象间的同步。
 2.能够对非我们创建的对象，即内部对象的状态改变作出响应.
 KVO缺点
 1.我们观察的属性必须使用strings来定义。因此在编译器不会出现警告以及检查；
 2.它只能用来对属性作出反应，而不会用来对方法或者动作作出反应.
 3.需要手动移除观察者。
 五. 怎么实现在一个线程中同时执行两个任务？
 怎么都做不到
 六. BASE64的用法?
 BASE64是网络传输中最常用的编码格式 - 用来将二进制的数据编码成字符串的编码方式.
 1> 能够编码,能够解码.
 2> 被很多的加密算法作为基础算法.
 七. 什么是消息推送
 可以绕过运营商,通过标准TCP/IP网络直接向这些手机发送消息.这些消息就称为推送消息.推送消息是通过Apple和Google掌控的互联网服务器发送的.推送消息从根本上就是设计用于与应用程序通信的.它们可以发送文本,多媒体文件和特定于应用程序的数据,例如警告声音和显示在应用程序图标上的标记等.
 八. 使用coredate有哪几种持久化存储机制
 属性列表
 对象归档
 数据库存储
 九. 协议是什么 有什么作用
 一系列方法的声明,某个类遵守了某个协议就拥有了该协议的所有方法的声明.就必须实现协议中规定的@require的方法.
 十.类变量的@protected, @private,@public, @package声明各有什么含义
 @public本类\子类\在其他类中都能访问
 @protected本类\子类中访问
 @private 私有的,只有本类中能访问
 @package 本包内使用，跨包不可以.
 
 

*/