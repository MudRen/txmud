// Room: /d/path1/tch_ft11.c

inherit ROOM;

void create()
{
	set("short", "ԣ��");
	set("long", @LONG
�������ԣ�룬��λ��ɽ���ض������һҪ���������ķ���
ͨ��ɽ���أ�����һֱͨ����츮������һ��С·���϶�ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tch_ft10",
  "northeast" : __DIR__"tch_ft12",
  "southeast" : __DIR__"ft_s1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
