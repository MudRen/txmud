// Room: /d/changan/furniture.c

inherit ROOM;

void create()
{
	set("short", "���¼�˽��");
	set("long", @LONG
����һ����Ĵ���������ڷ��Ÿ�ʽ�����ļҾߡ��Ե���
һЩ���ң���ϸ��ȥ�����ÿ���Ҿ߶�������ɫ������Ŀ��Ͼ����
�ű߹���һ��ľ����(sign)��
LONG
	);

	set(SAFE_ENV,1);
	set("item_desc",([
	"sign" : "����רӪ��ʽ�Ҿߣ������ list �õ����ۼҾߵ��嵥��
��(buy)�Ҿ�֮ǰ������ϸ�쿴(chakan)��������Ʒһ��
�۳��Ų��˻���
",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wroad7",
]));

	set("objects",([
	__DIR__"npc/f_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
