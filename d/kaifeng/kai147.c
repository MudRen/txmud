// Room: /u/w/wangs/b/kai147.c

inherit ROOM;

void create()
{
	set("short", "���ⶫ��");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣·����������������
�ܶ������Ǻ�«�ġ���ζС�Ե�С�̷����ؽֽ���������������
�ϣ������и��ܵ��������ķ�����������·��ͨ�����ֶ�·����
����ǰ�ɽ֣����򶫲�Զ���ǿ��ⶫ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai156",
  "west" : __DIR__"kai144",
  "northeast" : __DIR__"kai135",
  "east" : __DIR__"edoor",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
