// Room: /wiz/louth/k/kai5.c

inherit ROOM;

void create()
{
	set("short", "����䳡");
	set("long", @LONG
�����ǿ��⸮������䳡���䳡�����˽�����־����һλ��
���д��������ȭʦ����λȭʦ����ֻƾ��һ˫��ȭ���鿪��
�޵��֣������˺պ��������˳ơ���ȭ����С����ⶼ�Ƕ�ʮ��
ǰ�������ˣ���������ȭʦ�����ڼң��������£��㿪�������
����ÿ����̵�������ȭ�����ӹ��õ�Ҳ��ʵ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kai6",
  "west" : __DIR__"kai3",
]));
        set("objects",([
        __DIR__"npc/dizi": 3,
]));

	setup();
	replace_program(ROOM);
}
