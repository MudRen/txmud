// Room: /u/w/wangs/b/kai166.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǹ������ֵĽֵ����ֵ��ϼ����˸�ʽ�������ˣ����
���˿���������죬��Ϊ���Ǿ���һ�칤�������ͣ�����������
Ǭ�����·��������Ь�ӣ����ж�����ٶ���Щ�Խڼ��������
ʡ������Ǯ�����������Ѿ����Ծ�����������Ͼ����Ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai52",
  "west" : __DIR__"sdoor",
  "east" : __DIR__"kai165",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
