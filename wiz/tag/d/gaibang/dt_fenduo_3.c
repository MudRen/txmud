// dt_fenduo_3.c

inherit ROOM;

void create()
{
        set("short", "�쾮");
        set("long", @LONG
�տյ������쾮��û��ʲô�������������ע�⣬���˼�ֻ
�ڵ��ϱ�����ȥ��С�񡣻�ͷ�������ӣ��ƺ�Χǽ���ȷ���Ҫ��
�̵öࡣ����������û��������ǹɹ�ζ�ˣ��㲻�ɵ���������
������
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "west" : __DIR__"dt_fenduo",
        ]));

        set("objects",([
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
                me->move(__DIR__"dt_fenduo_4");
                message("vision", me->name() + "����һ�߷�ǽ���˹�����\n", environment(me), me);
        }
        return 1;
}
