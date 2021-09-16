// zhuque12.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()

{
	set("short", "码头木屋");
	set("long", @LONG
这里是一个用木头建成的码头小屋，小屋里面杂乱的堆积着
一些东西。小屋的西面就是码头，码头边挤满了要到靖海岛的人
群。
LONG);

	set("exits", ([
	"east" : __DIR__"zhuque3",
		]));
	setup();
}

int init()
{
        add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
         object me;
         me = this_player();
         if( !arg || arg != "didao")
         return notify_fail("什么？\n");
	
        if( me->query("class") != "jinghai")
         return notify_fail("什么？\n");

         if ( arg =="didao")
        {
         write("你拨开杂乱的东西，突然发现了一条地道，你迅速的钻了进去！\n");
         message("vision",
         me->name() + "趁你不注意，突然消失在一小屋的角落里面。\n",
                     environment(me), ({me}) );
         me->move(__DIR__"moon22");
         message("vision",
                  me->name() + "突然出现在小屋里，好象他在那里呆了很久，只是你没有发现！\n",
                             environment(me), ({me}) );
          }
          return 1;

}
