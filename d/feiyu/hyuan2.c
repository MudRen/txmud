// This is a room made by roommaker.

inherit ROOM;

private int have = 6;

void create()
{
        set("short", "小花园");
        set("long", @LONG
这是一处小花园，虽说花园不大，却开满了叫不上名字的四
季花朵争芳斗艳，香气扑鼻，其中几朵小紫花格外醒目。花园上
面搭着木架，木架上爬满了藤蔓。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hyuan3",
  "north" : __DIR__"hyuan5",
  "west" : __DIR__"hyuan1",
]));
	set("outdoors","feiyu");
        setup();
}

void init()
{
	add_action("do_pick",({ "pick","zhai" }));
}

int do_pick(string arg)
{
        object me = this_player(),ob;

	if(arg != "小紫花" )
		return notify_fail("你要摘什么？\n");

	if(!have)
		return notify_fail("小紫花都被摘没了。\n");

        if (!me->query_temp("pickzi"))
        {
                message_vision("$N轻轻的摘下了一朵小紫花。\n",me);
                me->set_temp("pickzi",1);
                have--;
                ob=new(__DIR__"obj/zflower");
                ob->move(me);
                return 1;
        }
        return notify_fail ("你已经摘过一朵小紫花了。\n");
}

