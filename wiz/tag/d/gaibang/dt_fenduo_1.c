// dt_fenduo_1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������Ժ�Ĳ������������߰��������һ��û����ʰ��
��һ����ؤ����ϯ�Ӻ���ʲô����������������˸���Ƿ������
����ֻ�������ò������ݣ��컨���ϻ���ʱ�������������
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "east" : __DIR__"dt_fenduo",
        ]));

        set("objects",([
        __DIR__"npc/dt_old_beggar" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
