// Room: /wiz/uudd/path2/liroom.c

inherit ROOM;

void create()
{
	set("short", "��ǹ����");
	set("long", @LONG
�����������ɽһ����������ǹ���꣬��������治
������������湻���ģ����ϰ壡��������һ�̹��⣡��
������������˷�������ѽ�����ã�һ��������Ŀ�ˮ���˳�
�������æ���ֲ��˲䡣Ȼ�����Χ���˲�����˼��Ц��Ц��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s14",
]));

	setup();
	replace_program(ROOM);
}
