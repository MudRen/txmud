// Room: /d/shaolin/tianwangdian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µ���������й��������֮���ķ�������
��ǽ���ϻ��������ֻص����ӣ�����������Ů�������ϵ�Ĥ��
�ţ���ϣ����������ʥ�ļ��־��������������ƹ�ʥ��������
Ժ�㳡��������̨��ͨ��ǰԺ�㳡��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taijie",
  "north" : __DIR__"m_square",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
