// /d/huashan/jindi_gate.c

inherit ROOM;

void create()
{
        set("short", "华山禁地大门");
        set("long", @LONG
这里是华山禁地的入口。这里一直由华山高手把守，华山弟
子没有得到许可是不能进去的。前面有一个上锈的铁门，似乎已
经很长时间没有打开过。从这里向西是小树林。
LONG
        );
        
        set("exits", ([
                "west" : __DIR__"sm_wood",
                "east" : __DIR__"xianshi_tomb",
        ]));

        set(SAFE_ENV, 1);
        set("no_beg_room",1);
        set("no_sleep_room",1);

        set("objects", ([
                __DIR__"npc/jindi_guard" : 2,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("asked_jindi_enter")  && dir == "east" )
                return notify_fail("两位华山高代弟子拦住了你，喝道：你不能进入华山禁地，请快离开！\n");

        if ( me->query_temp("asked_enter_again") )
                me->delete_temp("asked_enter_again");
 
        if ( me->query_temp("asked_enter_again") )
                me->delete_temp("asked_enter_again");
 
        me->delete_temp("asked_yan_about_secret");
        me->delete_temp("asked_ketou");
        me->delete_temp("asked_jindi_enter");
        return ::valid_leave(me, dir);
}


