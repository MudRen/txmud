// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
        set_name("��ʬ", ({ "zombie" }) );
        set("long",
                
"����һ�߱����÷�����ƵĽ�ʬ�������԰׵����Ͽ������κ�ϲŭ���֡�\n");
        set("max_gin", 400);
	set("gin",1);
        set("max_kee", 400);
        set("max_sen", 60);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("str", 60);
        set("cor", 40);
	set("haunt", 0);
        set("chat_chance", 15);
        set("chat_msg_combat", ({
                "��ʬ���з����ɺɵĽ�����\n",
                "��ʬ�����Ͽ�ʼ���Σ�һ��鴤�������Ƶش�С�\n",
                "��ʬ��ָ���ţ�ҧ���гݣ�¶��������Ц�ݡ�\n",
                (: do_bite :),
        }) );
        set_skill("unarmed", 30);
        set_skill("dodge", 30);

        set_temp("apply/damage", 15);

        setup();
}

void init()
{
	object	ob, targ;
	string	target;

	::init();
	if(query("haunt") == 1) {
        	target = query("haunttar");
		if(objectp(targ = present(target, environment()))) {
			message_vision("$N�۾���Ȼ�������૵�˵����" RED
"ɱ....��....$n....\n" NOR, this_object(), targ);
			this_object()->kill_ob(targ);
			this_object()->set_leader(targ);
			targ->kill_ob(this_object());
			set("haunt", 0);
                }
	}
}
int is_zombie() { return 1; }

void animate(object who)
{
        object weapon;
        string attack_skill;
        int attack,dodge,parry;

        set("possessed", who);
        set_leader(who);
        weapon=who->query_temp("weapon");
        if( objectp(weapon) )
                attack_skill = weapon->query("skill_type");
        else
                attack_skill = "unarmed";

        attack=who->query_skill(attack_skill)+who->query_temp("apply/attack");
        dodge=who->query_skill("dodge")+who->query_temp("apply/defense");
        parry=who->query_skill("parry")+who->query_temp("apply/defense");

//        set_temp("apply/attack",attack*10/11);
//        set_temp("apply/dodge",dodge*10/11);
//	set_temp("apply/parry",parry*10/11);
}

void dispell()
{
        object corpse;

        if( environment() ) {
                say( name() + "�����ص�����������Ϊһ̲Ѫˮ��\n");
        }

        destruct(this_object());
}

int heal_up()
{
        object master, leader;

        if( objectp(master = query("possessed")) 
        &&      (int)master->query("atman") > 10 ) {
                message("tell",
                        HIR + name() + 
"�����㣺��...��...Ҫ...��...��...��...��...\n" NOR,
                        master );
                master->add("atman", -10);
                master->receive_damage("gin", 1);
                ::heal_up();
                return 1;            
        } else {
                call_out("dispell", 1);
                return ::heal_up();
        } 
}

void do_bite()
{
        object *enemy;

        say( name() + "�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n" );
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("gin", 20);
                COMBAT_D->report_status(enemy[i], "gin");
        }
}
 
