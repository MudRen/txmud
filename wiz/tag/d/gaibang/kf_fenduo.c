// kf_fenduo.c

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ�ķ��˵Ļ�԰������������һƬС����������һЩ
����֮�࣬���ڳ������Ҳ�ɺ��ˡ�����������һ����ɽ��ɽ
�ϳ�������̦�����������Ѿ���ؤ��ķֶ������ˡ�
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "west" : "/d/kaifeng/kai190",
        ]));

        set("objects",([
        __DIR__"npc/kf_duozhu" : 1,
        ]));

        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}

