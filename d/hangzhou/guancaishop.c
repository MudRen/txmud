// Room: /d/hangzhou/guancaishop.c

inherit ROOM;

void create()
{
	set("short", "�ײ���");
	set("long", @LONG
����վ��һ��ײ��̵Ĵ��ſڣ�����������˸�ʽ�����Ĺ�
�ģ��Ա߻�����һЩֽǮ������֮��Ķ����������ϻ����ż���
�л��������ӳ��������ҡ�������������������ɭ����Ϣ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad2",
]));

	setup();
	replace_program(ROOM);
}
