// Room: /d/path3/k_h40.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����������ʯ�̳ɵĹٵ��ϣ���ʱ�����Ź����ĳ����ӵ��
����Ⱥ��������ȥ�����ǡ��������ã������պ����ĺ��ݳ��ˣ�
���ߣ�����һֱͨ�������¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/hangzhou/out_hangzhou_n",
  "north" : __DIR__"k_h39",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
