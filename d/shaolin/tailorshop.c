// Room: /wiz/uudd/path2/tailorshop.c

inherit ROOM;

void create()
{
	set("short", "�÷���");
	set("long", @LONG
������һ�Ҳ÷��̣�һ�߽��������ŵ�һ�ֲִ���ζ����ǽ
��Ҳ����һЩ�ֲ����ѣ��ϰ��߹��������ڨ����������Щũ
����·���̫����Ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s16",
]));

	setup();
	replace_program(ROOM);
}
