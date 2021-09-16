// /d/huashan/jindi_gate.c

inherit ROOM;

void create()
{
        set("short", "��ɽ���ش���");
        set("long", @LONG
�����ǻ�ɽ���ص���ڡ�����һֱ�ɻ�ɽ���ְ��أ���ɽ��
��û�еõ�����ǲ��ܽ�ȥ�ġ�ǰ����һ����������ţ��ƺ���
���ܳ�ʱ��û�д򿪹���������������С���֡�
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
                return notify_fail("��λ��ɽ�ߴ�������ס���㣬�ȵ����㲻�ܽ��뻪ɽ���أ�����뿪��\n");

        if ( me->query_temp("asked_enter_again") )
                me->delete_temp("asked_enter_again");
 
        if ( me->query_temp("asked_enter_again") )
                me->delete_temp("asked_enter_again");
 
        me->delete_temp("asked_yan_about_secret");
        me->delete_temp("asked_ketou");
        me->delete_temp("asked_jindi_enter");
        return ::valid_leave(me, dir);
}


