// jiaofu.c

inherit NPC;

int is_marry_ob() { return 1; }

void create()
{
	set_name("�η�", ({ "jiao fu" }));
	set("long", "��λ���Ӱ����Բ������Ц�ݡ�\n");
	set("gender","����");

	set("age",35);
	set("con",20);
	set("str",20);
	set(NO_KILL, 1);

	set("combat_exp",1500);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
