// Room: /d/path2/ch_k32.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ����������ϣ�·�������ǹ�ͺͺ��ɽ����ƽ��
�����ϡϡ����������һЩׯ�ڡ�ԶԶ��ȥ��һ���ŵ�Ҥ��ǰ��
һЩ����������ˣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ch_k33",
  "northdown" : __DIR__"ch_k31",
]));

	set("objects",([
	RIDE_DIR"w_horse" : 1,
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
