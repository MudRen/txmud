// Room: /wiz/louth/c/mingchafang.c

inherit ROOM;

void create()
{
	set("short", "���跻");
	set("long", @LONG
�����ǹ���Ʒ�����ĵ����跻���跻��İ���򵥶���ʧ��
�ţ������������ֳ������衱�����ա������Ȳ�ĺ���������ͬ
һ���輸�Գ�̸�ţ������С���æ��æ�£���������������
æ�Ĳ����ֺ��������������Ǹ������ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie2",
]));
        set("objects",([
        __DIR__"npc/fanboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
