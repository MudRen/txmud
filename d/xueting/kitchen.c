// Room: /d/snow/kitchen.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������һ����Ǯ�˼ҵĳ�����������������е���Ǯ��
�ҳ�������̫һ������û�ж����˼�Ѽ�����ɽ�亣ζ��������
Ǯ��Ҳ��ʡ�Լ��ò�����Ǯ�ģ���������������ϱߣ�������ס�ˣ�
���������������Χǽ��
LONG
        );
//        set("objects", ([
//                "/obj/example/dumpling" : 3
//        ]) );
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg!="Χǽ" ) return 0;
        message_vision("$N��������Χǽ�����˼��·��˹�ȥ��\n", this_player());
        this_player()->move(__DIR__"epath");
        message("vision", this_player()->name() + "��Χǽ����һͷ���˳�����\n",
                environment(this_player()), this_player());
        return 1;
}
