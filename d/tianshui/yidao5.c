// Room: /u/xiaozhen/yidao5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������Ĵ������·�����������������ӵġ���
�̵ġ����Ŵ󳵵�������ﲻ����·�߻���һЩС�̷��ڽ�����
�ǳ����֡���ʱ�������������߷ɳ۶���������һ·��������
������ˮ�򣬱�����Ǳ߹ش�Ӫ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/junying/gate",
  "south" : __DIR__"yidao4",
]));
	set("no_clean_up", 0);
	set("outdoors","xiaozhen");
	setup();
	replace_program(ROOM);
}
