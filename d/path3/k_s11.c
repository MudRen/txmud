// Room: /d/path3/k_s11.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ������С·�ϣ�·�����Գ����˲β������ӡ�
ʱ���������������У���֪��ʲô��İ�������ܿ���һ�£�
û�з���ʲô����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s12",
  "north" : __DIR__"k_s10",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 4,
]));

        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
