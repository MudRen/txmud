// Room: /d/shaolin/w_pei.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������µ���������Ĥ�ݵ�������һ������
Ϊ���﹩�������������������İ����ӷ�ֻ������������
΢Ц�����Ͻ��Ź���ӡ���������վ�Ź����������ʹ���������
��в�̡�������ͣ�����Ľ��㣬�ͷ���ͷ���̾����̾�����
�����֡����������Ǵ��۱��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baodian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
