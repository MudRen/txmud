// Room: /d/path3/k_s21.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����λ�ڳ������α�������������½�����һ�飬���ĵĽ�
ˮ�����˴�Ҳ�������ٶȡ�����ϸ��ȥ��ֻ���������Ϻз�ں�
ˮ��������ȥ��������������ʵĳ�����з�������(fish)��ֻ
��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"k_s20",
    "west" : __DIR__"k_s22",
]));
        set("cannot_build_home", 1);
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
