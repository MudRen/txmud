// Room: /d/shaolin/baodian.c

inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long", @LONG
�����������µĴ��۱��һ���źò�ׯ�ϣ�һ�����ɸߵ�
����Ĳ��ʥ�������У������ǰ��С���Ҷ��в�̡���������
������ʮ���޺�����̬���졣���ڴ��ܸߣ�ǰ�湩���Ϸ�����
���ַ�������������������Ʈ����ʹ��о��������С�ͷ�
���ޱ�����������ͬ�����������ǰ��������ϡ�������������
�������������ƹ���������һ����������ϱ���
��ʯ�ױ�����Ժ�㳡�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"yongdao1",
  "southdown" : __DIR__"m_square",
  "east" : __DIR__"e_pei",
  "west" : __DIR__"w_pei",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
