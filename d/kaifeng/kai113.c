// Room: /u/w/wangs/b/kai113.c

inherit ROOM;

void create()
{
	set("short", "�����Ͻ�");
	set("long", @LONG
�������ϴ���ϵ����������������̿ͣ��е������ϲɫ��
�еĳ������棬�����ڿ���������ҵ��̨��վ�ȽŸ������Ǻ���
�׵����鰡���кܶ���һҹ֮�䱩����Ҳ�������֮�����ҵ�
����������ı�����Ͼ�������һĻĻ�������š������ǳ��Ͽ�
ջ���������Լ�լ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai106",
  "south" : __DIR__"sdoor",
  "west" : __DIR__"kai63",
  "east" : __DIR__"kai115",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
