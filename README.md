# Qt六种方式退出当前程序
- QCoreApplication::exit(0);   // 0是状态还可以是其他的值

- QCoreApplication::quit();

- QApplication::exit(0);          // QApplication是继承QCoreApplication的。

- QApplication::quit();

- close();  QApplication有个常用属性qApp->quitOnLastWindowClosed(true);  当最后一个窗口关闭时自动调用exit();

- QApplication::closeAllWindows(); 关闭多个窗口，窗口可以接受close事件。