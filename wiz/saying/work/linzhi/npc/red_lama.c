//red_lama.c ���ڹ����µĺ������
inherit NPC;
void create()
{
        set_name("����", ({ "lama" }) );
        set("age", 28+random(7));
        set("long", "���ڹ����µ����\n");
        
        set("str",25);
        set("per",10);
        set("inquiry",([
        "���ڹ�����":"Сɮ���Ǵ��ڹ����µ����",
        "�ø»��":"��𣿻��������ƽ�����ܿ����ġ�",
]));        
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
}
