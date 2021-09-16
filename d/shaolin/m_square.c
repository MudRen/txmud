// Room: /d/shaolin/m_square.c

inherit ROOM;

void create()
{
	set("short", "��Ժ�㳡");
	set("long", @LONG
�����������µ���Ժ�㳡���㳡������һ���޴��ʯ����¯��
�������˵������������ĵط��ˣ����µ�����ɮ�ᣬ������
�ף���������������ε�������ٲȻ����ʫ�����ǣ�
        ���ҹ������ţ�������Ƹ����衣
        ���ĺ�ɽ��ĺӰ��âЬ�ŵ�ӡ̦�ۡ�
        �ֻ�ʮ����Ϊ�ϣ�������ǧ��ҵ�ꡣ
        ��Ը����徲����б�����̰�ƻ衣
�����ﶫ�����߷ֱ𶫹㳡�����㳡��������ΰ�Ĵ��۱����
�������µ������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"baodian",
  "south" : __DIR__"tianwangdian",
  "east" : __DIR__"e_square",
  "west" : __DIR__"w_square",
]));
        set("objects", ([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
