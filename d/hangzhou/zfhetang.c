// Room: /d/hangzhou/zfhetang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ǰ��һ��СС�ĺ�����������������󣬵��ɻ�ȴ����
����ïʢ����ͷ����ˮ�棬�����β����������ڽ�����ɢ����
��Ҷ�ϵ�¶ˮ���ź�Ҷ��ҡ�ڣ����������ˮ�С�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath3",
]));

	setup();
	replace_program(ROOM);
}
