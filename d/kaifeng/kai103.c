// Room: /u/w/wangs/b/kai103.c

inherit ROOM;

void create()
{
	set("short", "�����Ͻ�");
	set("long", @LONG
�������ϴ���ϵ����������������̿ͣ��е������ϲɫ��
�еĳ������棬�����ڿ���������ҵ��̨��վ�ȽŸ������Ǻ���
�׵����鰡���кܶ���һҹ֮�䱩����Ҳ�������֮�����ҵ�
����������ı�����Ͼ�������һĻĻ�������š�������һ��Ƥ
���꣬������һ�����ء�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai106",
  "north" : __DIR__"kai100",
  "west" : __DIR__"kai104",
  "east" : __DIR__"kai105",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
