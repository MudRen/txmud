// Room: /d/jinghai/th02.c

inherit ROOM;

void create()
{
        set("short", "�һ�ɽׯǰ����");
        set("long", @LONG
����������ǰ��һ�������ʮ���Ļ��Ǻӣ������ɶ����
���������һ˫������ľ���ţ��ɴ�������������������ȥ����
һ����¥���������Ʈ�Ρ������Ĺ��г����Ϸ����š��һ�
ɽׯ���ĸ�������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"th01",
]));
        set("outdoors","jinghai");

        setup();
}

void init()
{
        add_action("do_han", "yell");
}

int do_han(string arg)
{
        object me, key, nroom;
        string passwd;

        me = this_player();

        if( !arg
        || !(passwd = "������")
        || (arg != passwd))
                return notify_fail("�㳶�Ų��Ӻ��˼�ɤ�ӣ���Χ����û���κη�ӳ��\n");

        if( !(key = present("zhu ling", me))
        || (key->query("master") != me->query("id")))
                return notify_fail("����̽���˸��Դ����˿��������˻�ȥ��\n");

        if( !(nroom = find_object(__DIR__"th03")) )
                nroom= load_object(__DIR__"th03");

        set("exits/westup", __DIR__"th03");

        message_vision("����̽���˸��Դ����˿�$N��$N�Ͻ������е������ó������˻Ρ�\n", me);
        message_vision("ֻ���������˺���Щʲô�������������¡�\n", me );

        me->delete_temp("jinghai_have_ling/zhu");
        destruct(key);

        call_out("open",10,me);
        return 1;
}

void open()
{
        message("vision", "ֻ���������˺���:����...���š�\n", this_object() );
        delete("exits/westup");
}
