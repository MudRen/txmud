// Room: /d/path1/zjz4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ʈ�����������죬������ǰ������ˡ����ߵ������
֪ʲôԭ�ʣ�����ͻȻ�е�һ�ֲ��������Ĵ����˿���ȴʲôҲ
û�з��֡�����һ��С·ͨ������ͤ������ͨ���Թ��ڣ�������
������Ƭ���־͵���Ҵ��ˡ�

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"py1",
  "north" : __DIR__"zjz3",
  "southeast" : __DIR__"zjz5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
