// Room: /wiz/louth/c/caotang.c

inherit ROOM;

void create()
{
	set("short", "�Ÿ�����");
	set("long", @LONG
������λ�ڳɶ�����佻�Ϫ�ϵĶŸ����ã����ƴ�ΰ��ʫ��
�Ÿ���Ԣʱ�Ĺʾӣ��Ÿ��ڴ˾�ס���������ʱ���£�д����
������ʮ������ʵ����ʫ�������˾������ͣ����ڲ�����ַ����
�������ƾ���������߿���������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao5",
]));

	setup();
	replace_program(ROOM);
}
