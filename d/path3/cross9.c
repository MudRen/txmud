// Room: /d/path3/cross9.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������λ�����ɽ���µ�һ��С·����һ������ɽ����Ӱ��
�����ƺ�����������㻹��С�����µĺá�ǰ�治Զ����ͭ��
�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cross8",
  "east" : __DIR__"k_h12",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
