// Room: /d/shaolin/e_pei.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������µ����������ŵ���ҩʦ�������Ƕ�����
�����������֮��������ҩʦ�����;���������в�̡�������
һЩ��������������ʥ�񡣴����ߴ�տ���ʮ�ֵ�׳�ۡ�����
�����Ǵ��۱��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baodian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
