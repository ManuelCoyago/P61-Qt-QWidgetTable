#include "personadialog.h"
#include "ui_personadialog.h"
#include "QMessageBox"
PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    QString edad = ui->inEdad->text();

    // Validación: verificar si algún campo está vacío
    if (nombre.isEmpty() || apellido.isEmpty() || telefono.isEmpty() || email.isEmpty()|| edad.isEmpty())
    {
        QMessageBox::warning(this, "Advertencia", "Por favor, complete todos los campos antes de continuar.");
        return; // Salir de la función sin continuar
    }

    // Validación: verificar si el número de teléfono tiene 10 dígitos
    if (telefono.length() != 10)
    {
        QMessageBox::warning(this, "Advertencia", "El número de teléfono debe tener 10 dígitos.");
        return; // Salir de la función sin continuar
    }

    // Validación: verificar si el correo posee al menos un punto y un "@"
    if (!email.contains(".") || !email.contains("@"))
    {
        QMessageBox::warning(this, "Advertencia", "El correo electrónico debe contener al menos un punto (.) y un símbolo de arroba (@).");
        return; // Salir de la función sin continuar
    }

    // Si todas las validaciones pasan, crear la instancia de Persona y continuar
    this->m_persona = new Persona(nombre, apellido, telefono, email, edad);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}

