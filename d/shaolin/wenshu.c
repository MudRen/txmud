// Room: /d/shaolin/wenshu.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������µ�����һ������㿴�����й����ŵģ���
������㷨������ֻ�����˴�����ʨ�ϵ�һ�����������ϣ��ޱ�
���飬����������˳�֮Ϊ���ǵ����Ϊ���������ֳƴ�����
����Ե�ʡ������������Ǻ�Ժ�Ĺ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad4",
]));

	set("objects", ([
	__DIR__"npc/huizheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
