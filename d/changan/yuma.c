// Room: /d/changan/yuma.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������Ȼȫ��ǧ��ѡһ�ĺ����ˣ����ߵ��������
ϸ�鿴���������˼�ʮƥ����ȫ����һɫ�Ĵ�����������������
��Ⱥ��΢��ɧ���������Աߵ�һ����С�������ȴֻ����һƥ��
ֻ�������øߴ��쳣��ȫ���ë������һ��鵭��ɫ�İߵ㣬��
�����࣬�����񿥷Ƿ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jinwei",
]));

	setup();
	replace_program(ROOM);
}
