//maple_e.c �������Թ����յ�
inherit ROOM;

void create()
{

        set("short","������");
        set("long",@long
����һƬ���ķ����֣�ֻ���紵Ҷ����ɳɳ�������ƺ�
���е�ˮ����Ϣ��
long
);
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"maple/exit",
        "west":__DIR__"lake_e",
]));
        setup();
        replace_program(ROOM);
}
