//maple_s.c �������Թ������
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
        "north":__DIR__"lz_eroad5",
        "south":__DIR__"maple/entry",
]));
        setup();
        replace_program(ROOM);
}
