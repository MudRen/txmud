// Room: /d/path3/k_h1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�������̳ɵĹٵ���·�������˲��ٵ���ˮ������ʮ
�����֣������Ǻ�«�ġ���糵�ġ��������׵��Ĵ����ǡ����
��ʱ�����ţ�������ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_h2",
  "west" : "/d/kaifeng/out_kaifeng_e",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
