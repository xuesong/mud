// mudao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mu dao", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10);
		set("material", "wood");
		set("long", "����һ��ľ�ƵĶ̵������ҵ����ô˵���ϰ������\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(3);
	setup();
}