// /d/changan/duchang1.c

inherit ROOM;

void create()
{
        set("short", "赌坊后院");
        set("long", @LONG
这里就是全国闻名的长安赌坊后院。赌坊里面此起彼伏的叫
喊声，银子、元宝叮叮当当的碰撞声使你也不禁血液沸腾起来。
这里到显得特别的安静，一般赌客们累了，就会来这里呼吸一下
新鲜的空气，调整一下心情。
LONG
        );
        
        set("exits", ([
                "east" : __DIR__"duchang",
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
         if ( arg =="didao")
        {
         write("你拨开墙角的草丛，突然发现了一条地道，你迅速的钻了进去！\n");
         message("vision",
         me->name() + "趁你不注意，突然钻入墙角的草丛中，消失不见了！\n",
                     environment(me), ({me}) );
         me->move("/d/houjizhen/shangang");
         message("vision",
                  me->name() + "突然出现在你的眼前，仿佛他已经在那里好久了！\n",
                             environment(me), ({me}) );
          }
          return 1;

}