// dt_fenduo_4.c

inherit ROOM;

void create()
{
        set("short", "�յ�");
        set("long", @LONG
��������ƾɴ�Ժ����Ŀյأ��Ӳݴ�����û������Ľ��ס�
���뷱���Ĵ�ͬ���ﾹȻ������ô��һ��յأ��㲻�ɵð�����
�֡�һ����ؤ�������ڲ�Զ��ˣ�Ź��ӡ�
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
        ]));

        set("objects",([
                __DIR__"npc/dt_duozhu" : 1,
        ]));
 
        set("outdoors", "datong");

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg != "Χǽ") return 0;
        if ( arg =="Χǽ")
        {
                message_vision("$N˫��һ�ţ�������ǽȥ��\n", me);
                me->move(__DIR__"dt_fenduo_3");
                message("vision", me->name() + "����һ�߷�ǽ���˹�����\n", environment(me), me);
        }
        return 1;
}
