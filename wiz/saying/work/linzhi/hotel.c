//hotel.c 林芝村的客栈
inherit ROOM;
void create()
{
        set("short", "老刀客栈");
        set("long", @LONG
这里是林芝村唯一的客栈，不过因为外来人不是很多，所以
生意也是一般。大多数都是从拉萨来的客人，极有可能是来找村
长－－也就是族长的。客栈老板好像在拉萨学过功夫，跟村长也
有点交情。
LONG
        );
        set(SAFE_ENV,1);
        set("no_sleep_room",1);
        set("item_desc", ([
        "paizi" : "楼上客房，每晚三两白银。\n",
]));
        set("objects", ([
        __DIR__"npc/waiter":1,
]));
        set("exits", ([
        "east" : __DIR__"lz_wroad1",
        "up" : __DIR__"hotel2",
]));
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎么着，想白住啊！\n");
        if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
                return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");
        if ( me->query_temp("rent_paid") && dir == "east" )
                me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}
