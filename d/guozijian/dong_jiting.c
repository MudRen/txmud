// Room: /d/guozijian/dong_jiting.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "东井亭");
	set("long", @LONG
这里是东井亭，这里是一片绿地，偶尔有一俩只兔子跳来跳
去，两边房子的门都锁着，西面是一条青石甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"yongdao1",
]));

	set("outdoors","guozijian");
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
	object box,me;
	me = this_player();
	if( me->is_busy())
              return notify_fail("你正忙着呢！\n");
	me->start_busy(2);
	if( random(10) == 1 ) {
          message_vision("$N在草地上翻来翻去，终于找到一个把钥匙。\n",me);
	  box = new(__DIR__"obj/key1");
	  box->move(__FILE__);
	}else
          message_vision("$N在草地上翻来翻去，虽然掘地三尺，可是什么都没有找到。\n",me);
	return 1;
}