// Room: /u/w/wangs/b/kai138.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
���������Ҫ�ֵ�������ͨ�����Ľ֡�����С�ֺ������
���ֽ����ã���Ȼ�������ı��߾��ǿ�����������Ĵ�����
��¥������ͨ������ǵ����š�����������ΰ��ܺã�����ϵ�
����Ҳ������Ϊ��ȫ���ġ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai140",
  "north" : __DIR__"kai139",
  "west" : __DIR__"kai137",
  "east" : __DIR__"kai141",
]));

	set("outdoors","kaifeng");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
