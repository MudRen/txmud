// Room: /d/fengtian/er.c

inherit ROOM;

void create()
{
	set("short", "����̫��");
	set("long", @LONG
����̫���Ͼ�ס���������Ԫ�����һֱû�����ã�����
����Ȣ�����ϣ������˳��ĵ��ܶ�ׯ����������Ҳ�Ǹ�С�ұ���
�����Ǻ��м�ʶ�������ܻ��ֽ������ġ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wo",
]));

	setup();
	replace_program(ROOM);
}
