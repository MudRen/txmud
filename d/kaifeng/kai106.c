// Room: /u/w/wangs/b/kai106.c

inherit ROOM;

void create()
{
	set("short", "�����Ͻ�");
	set("long", @LONG
�������ϴ���ϵ����������������̿ͣ��е������ϲɫ��
�еĳ������棬�����ڿ���������ҵ��̨��վ�ȽŸ������Ǻ���
�׵����鰡���кܶ���һҹ֮�䱩����Ҳ�������֮�����ҵ�
����������ı�����Ͼ�������һĻĻ�������š����������ҩ
�̣�������һ������ݡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai103",
  "south" : __DIR__"kai113",
  "west" : __DIR__"kai111",
  "east" : __DIR__"kai112",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
