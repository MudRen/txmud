// Room: /d/shaolin/yongdao1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����������µ�һ����ʯ��������ʯ�̳ɵĵ�·����ȥ��
���������������·ƽʱ�ߵ��˺ܶ࣬�����Ѿ�ĥ�ĺ�ƽ���ˡ�
�ڵ���������һЩ����ʯ�⣬ȷ��֪����ʲô�õġ���������
����ʯ��ֱͨ��Ժ����������̨���Ǵ��۱�������ϺͶ���
�ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"rroad3",
  "southwest" : __DIR__"lroad3",
  "north" : __DIR__"yongdao2",
  "southup" : __DIR__"baodian",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
